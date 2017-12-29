using System;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class Style : Object
    {
		public Style(IntPtr raw) : base(raw) { }

        public Style() : base(IntPtr.Zero) { }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_style_alignrect_get(LayoutDirection direction, Alignment alignment, IntPtr size, IntPtr rectangle);
		public static Rectangle AlignedRect(LayoutDirection direction, Alignment alignment, Size size, Rectangle rectangle)
		{
			return new Rectangle (qt_style_alignrect_get (direction, alignment, size.Handle, rectangle.Handle));
		}
    }
}
