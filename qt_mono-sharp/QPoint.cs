using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Point
	{
		IntPtr Raw;
		public Point (IntPtr raw)
		{
			Raw = raw;
		}
		public int X
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
		public int Y
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
	}
}

