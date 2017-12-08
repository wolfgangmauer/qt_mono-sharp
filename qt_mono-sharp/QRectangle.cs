using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Rectangle
	{
		IntPtr Raw;
		public Rectangle (IntPtr raw)
		{
			Raw = raw;
		}

//		public int X
//		{
//			get { return rawX; }
//			set { rawX = value; }
//		}
//		public int Y
//		{
//			get { return rawY; }
//			set { rawY = value; }
//		}
//		public int Width
//		{
//			get { return rawWidth; }
//			set { rawWidth = value; }
//		}
//		public int Height
//		{
//			get { return rawHeight; }
//			set { rawHeight = value; }
//		}
//
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

