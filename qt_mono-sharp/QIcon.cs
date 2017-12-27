using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Icon
	{
		public IntPtr Handle { get ; private set; }

		public Icon (IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_icon_from_pixmap_new (IntPtr pixmap);
		public static Icon FromPixmap(Pixmap pixmap)
		{
			return new Icon(qt_icon_from_pixmap_new(pixmap.Handle));
		}
	}
}

