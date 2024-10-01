using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Painter
	{
		public IntPtr Handle { get ; private set; }

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_painter_new (IntPtr pixmap);
		public Painter (Pixmap pixmap)
		{
			Handle = qt_painter_new (pixmap.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_painter_pixmap_draw (IntPtr raw, int x, int y, IntPtr pixmap);
		public void DrawPixmap(int x, int y, Pixmap pm)
		{
			qt_painter_pixmap_draw (Handle, x, y, pm.Handle);
		}
	}
}

