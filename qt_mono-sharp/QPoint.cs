using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Point
	{
		public IntPtr Handle { get ; private set; }

		public Point (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_point_new(int x, int y);
		public Point (int x, int y)
		{
			Handle = qt_point_new(x, y);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_point_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_point_x_set(IntPtr raw, int x);
		public int X
		{
			get{ return qt_point_x_get (Handle); }
			set{ qt_point_x_set (Handle, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_point_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_point_y_set(IntPtr raw, int y);
		public int Y
		{
			get{ return qt_point_y_get (Handle); }
			set{ qt_point_y_set (Handle, value); }
		}
	}
}

