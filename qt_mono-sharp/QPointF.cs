using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class PointF
	{
		IntPtr Raw;
		public PointF (IntPtr raw)
		{
			Raw = raw;
		}
		public double X
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
		public double Y
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
	}
}

