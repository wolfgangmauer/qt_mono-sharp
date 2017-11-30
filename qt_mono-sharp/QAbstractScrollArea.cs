using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public abstract class ScrollArea : Frame
    {
		public enum SizeAdjustPolicy {
			AdjustIgnored,
			AdjustToContentsOnFirstShow,
			AdjustToContents
		}

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_abstractscrollarea_new(IntPtr parent);
        
		protected ScrollArea(IntPtr raw) : base(raw) { }

		protected ScrollArea(Widget parent) : base(IntPtr.Zero)
        {
			Raw = qt_abstractscrollarea_new(parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
