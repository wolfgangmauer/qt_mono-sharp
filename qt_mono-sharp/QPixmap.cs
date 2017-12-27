using System;
using System.Runtime.CompilerServices;
using System.Reflection;
using System.IO;

namespace Qt
{
	public class Pixmap
	{
		public IntPtr Handle { get ; private set; }

		public Pixmap (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_pixmap_new (string filename, string format, ImageConversionFlag flags);
		public Pixmap(string filename, string format = null, ImageConversionFlag flags = ImageConversionFlag.AutoColor)
		{
			Handle = qt_pixmap_new (filename, format, flags);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_pixmap_data_new (byte[] data, int len, string format);
		public static Pixmap FromResource(string resource, string format, Assembly assembly)
		{
			if (assembly == null)
				assembly = Assembly.GetExecutingAssembly();
			using (Stream stream = assembly.GetManifestResourceStream(resource))
			using (BinaryReader reader = new BinaryReader(stream))
			{
				if (stream == null)
					return null;
				return new Pixmap(qt_pixmap_data_new(reader.ReadBytes((int)stream.Length), (int)stream.Length, format));
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_pixmap_scaled(IntPtr raw, IntPtr size, AspectRatioMode aspectMode, TransformationMode mode);
		public Pixmap Scale(Size size, AspectRatioMode aspectMode = AspectRatioMode.IgnoreAspectRatio, TransformationMode mode = TransformationMode.FastTransformation)
		{
			return new Pixmap(qt_pixmap_scaled(Handle, size.Handle, aspectMode, mode));
		}

		public Pixmap Scale(int width, int height)
		{
			return this; //Scale(new Size(width, height), AspectRatioMode.KeepAspectRatio);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_pixmap_rotate (IntPtr raw, double deg);
		public Pixmap Rotate(double deg)
		{
			return new Pixmap(qt_pixmap_rotate(Handle, deg));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern bool qt_pixmap_save (IntPtr raw, string filename, string format, int quality);
		public bool Save(string fileName, string format=null, int quality=-1)
		{
			return qt_pixmap_save(Handle, fileName, format, quality);
		}
	}
}

