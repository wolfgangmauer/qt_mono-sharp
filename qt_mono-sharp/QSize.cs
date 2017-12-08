using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Size
	{
		IntPtr Raw;
		public Size (IntPtr raw)
		{
			Raw = raw;
		}

		public int Width
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
		public int Height
		{
			[MethodImpl (MethodImplOptions.InternalCall)]
			get;
			[MethodImpl (MethodImplOptions.InternalCall)]
			set;
		}
	}
}

