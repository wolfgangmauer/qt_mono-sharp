using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Size
	{
		public IntPtr Handle { get ; private set; }

		public Size (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_size_new(int width, int height);
		public Size (int width, int height)
		{
			Handle = qt_size_new (width, height);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_size_width_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_size_width_set(IntPtr raw, int width);
		public int Width
		{
			get{ return qt_size_width_get (Handle); }
			set{ qt_size_width_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_size_height_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_size_height_set(IntPtr raw, int width);
		public int Height
		{
			get{ return qt_size_height_get (Handle); }
			set{ qt_size_height_set (Handle, value); }
		}
	}
}

