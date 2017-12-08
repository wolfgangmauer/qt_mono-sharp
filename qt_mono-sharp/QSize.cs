using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Size
	{
		IntPtr raw;
		public Size (IntPtr raw)
		{
			this.raw = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_size_width_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_size_width_set(IntPtr raw, int width);
		public int Width
		{
			get{ return qt_size_width_get (raw); }
			set{ qt_size_width_set (raw, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_size_height_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_size_height_set(IntPtr raw, int width);
		public int Height
		{
			get{ return qt_size_height_get (raw); }
			set{ qt_size_height_set (raw, value); }
		}
	}
}

