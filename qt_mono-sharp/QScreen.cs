using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Screen : Object
	{
		public Screen (IntPtr raw)
			: base(raw)
		{
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_screen_window_grab(IntPtr raw, IntPtr window, int x, int y, int w, int h);
		public Pixmap GrabWindow(IntPtr window, int x = 0, int y = 0, int w = -1, int h = -1)
		{
			return new Pixmap(qt_screen_window_grab (Handle, window, x, y, w, h));
		}
	}
}

