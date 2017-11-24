using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class SpacerItem : LayoutItem
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern IntPtr qt_spaceritem_new(IntPtr parent);

		protected SpacerItem(IntPtr raw) : base(raw) { }

        public SpacerItem(Object parent = null) : base(IntPtr.Zero)
        {
            if (GetType() != typeof(SpacerItem))
            {
                CreateNativeObject();
                return;
            }
			Raw = qt_spaceritem_new(parent != null ? parent.Handle : IntPtr.Zero);
        }
    }
}
