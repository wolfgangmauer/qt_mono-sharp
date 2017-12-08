using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Rectangle
	{
		IntPtr raw;
		public Rectangle (IntPtr raw)
		{
			this.raw = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_x_set(IntPtr raw, int x);
		public int X
		{
			get{ return qt_rectangle_x_get (raw); }
			set{ qt_rectangle_x_set (raw, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_y_set(IntPtr raw, int y);
		public int Y
		{
			get{ return qt_rectangle_y_get (raw); }
			set{ qt_rectangle_y_set (raw, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_width_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_width_set(IntPtr raw, int width);
		public int Width
		{
			get{ return qt_rectangle_width_get (raw); }
			set{ qt_rectangle_width_set (raw, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_height_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_height_set(IntPtr raw, int width);
		public int Height
		{
			get{ return qt_rectangle_height_get (raw); }
			set{ qt_rectangle_height_set (raw, value); }
		}
	}
}

