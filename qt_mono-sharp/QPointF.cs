using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class PointF
	{
		public IntPtr Handle { get ; private set; }

		public PointF (IntPtr raw)
		{
			Handle = raw;
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern double qt_pointf_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_pointf_x_set(IntPtr raw, double x);
		public double X
		{
			get{ return qt_pointf_x_get (Handle); }
			set{ qt_pointf_x_set (Handle, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern double qt_pointf_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_pointf_y_set(IntPtr raw, double y);
		public double Y
		{
			get{ return qt_pointf_y_get (Handle); }
			set{ qt_pointf_y_set (Handle, value); }
		}
	}
}

