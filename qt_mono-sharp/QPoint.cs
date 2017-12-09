using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Point
	{
		IntPtr raw;

		public IntPtr Handle { get { return raw; } }

		public Point (IntPtr raw)
		{
			this.raw = raw;
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_point_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_point_x_set(IntPtr raw, int x);
		public int X
		{
			get{ return qt_point_x_get (raw); }
			set{ qt_point_x_set (raw, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_point_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_point_y_set(IntPtr raw, int y);
		public int Y
		{
			get{ return qt_point_y_get (raw); }
			set{ qt_point_y_set (raw, value); }
		}
	}
}

