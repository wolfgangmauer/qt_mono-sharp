using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public enum ResizeMode
	{
		Interactive,
		Stretch,
		Fixed,
		ResizeToContents,
		Custom = Fixed
	}

    public class HeaderView : ItemView
    {
		public HeaderView(IntPtr raw) 
		{
			Raw = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_headerview_visible_set (IntPtr raw, bool visible);
		public bool Visible
		{
			set{ qt_headerview_visible_set (Handle, value); }
		}
    }
}
