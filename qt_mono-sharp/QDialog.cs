using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Dialog : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_dialog_new (Dialog thisObject, IntPtr parent, WindowType f);

		protected Dialog () { }

		protected Dialog (IntPtr raw) : base(raw) { }

		public Dialog (Widget parent) : this(parent, 0) {}

		public Dialog (Widget parent, WindowType f)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_dialog_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		public Dialog (Widget parent, string uiFile)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_dialog_new (this, parent != null ? parent.Handle : IntPtr.Zero, 0);
			new UiLoader ().Load (this, uiFile);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_dialog_exec (IntPtr raw);
		public int Exec()
		{
			return qt_dialog_exec (Handle);
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

