using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class PointF
	{
		IntPtr raw;
		public PointF (IntPtr raw)
		{
			this.raw = raw;
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern double qt_pointf_x_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_pointf_x_set(IntPtr raw, double x);
		public double X
		{
			get{ return qt_pointf_x_get (raw); }
			set{ qt_pointf_x_set (raw, value); }
		}
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern double qt_pointf_y_get(IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_pointf_y_set(IntPtr raw, double y);
		public double Y
		{
			get{ return qt_pointf_y_get (raw); }
			set{ qt_pointf_y_set (raw, value); }
		}
	}
}

