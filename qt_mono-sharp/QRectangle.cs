using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Rectangle
	{
		public IntPtr Handle { get ; private set; }

		public Rectangle (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_x_set(IntPtr raw, int x);
		public int X
		{
			get{ return qt_rectangle_x_get (Handle); }
			set{ qt_rectangle_x_set (Handle, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_y_set(IntPtr raw, int y);
		public int Y
		{
			get{ return qt_rectangle_y_get (Handle); }
			set{ qt_rectangle_y_set (Handle, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_width_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_width_set(IntPtr raw, int width);
		public int Width
		{
			get{ return qt_rectangle_width_get (Handle); }
			set{ qt_rectangle_width_set (Handle, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_rectangle_height_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_rectangle_height_set(IntPtr raw, int width);
		public int Height
		{
			get{ return qt_rectangle_height_get (Handle); }
			set{ qt_rectangle_height_set (Handle, value); }
		}
	}
}

