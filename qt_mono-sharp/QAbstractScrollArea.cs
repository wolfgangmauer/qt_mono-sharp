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

		protected ScrollArea ()	{ }

		protected ScrollArea (IntPtr raw) : base(raw) { }

		public ScrollArea(Widget parent)
        {
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_abstractscrollarea_new(this, parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
