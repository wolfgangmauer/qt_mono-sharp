using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class ScrollArea : Frame
    {
		public enum SizeAdjustPolicy {
			AdjustIgnored,
			AdjustToContentsOnFirstShow,
			AdjustToContents
		}

        [MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_abstractscrollarea_new(ScrollArea thisObject, IntPtr parent);
        
		protected ScrollArea (IntPtr parent) : base(parent)
		{
			if (GetType () != typeof(ScrollArea))
				return;
			Raw = qt_abstractscrollarea_new (this, parent);
		}

		protected ScrollArea(Widget parent) : base(IntPtr.Zero)
        {
			if (GetType () != typeof(ScrollArea))
				return;
			Raw = qt_abstractscrollarea_new(this, parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
