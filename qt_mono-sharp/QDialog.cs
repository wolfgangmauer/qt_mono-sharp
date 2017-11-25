using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Dialog : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_dialog_new (Dialog thisObject, IntPtr parent, WindowType f);

		protected Dialog (IntPtr raw) : base(raw) {}

		public Dialog () : this(null, 0) {}

		public Dialog (Widget parent) : this(parent, 0) {}

		public Dialog (Widget parent, WindowType f) : base(IntPtr.Zero)
		{
			Raw = qt_dialog_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_dialog_exec (IntPtr raw);
		public int Exec()
		{
			var retVal = qt_dialog_exec (Handle);
			return retVal;
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern bool qt_dialog_modal_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_dialog_modal_set(IntPtr raw, bool modal);
        public bool Modal
        {
            get
            {
				return qt_dialog_modal_get(Handle);
            }
            set
            {
				qt_dialog_modal_set(Handle, value);
            }
        }
    }
}

