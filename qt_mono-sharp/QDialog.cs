using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Dialog : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_dialog_new (Dialog thisObject, IntPtr parent, WindowType f);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_dialog_delete (IntPtr raw);
		protected Dialog () { }

		protected Dialog (IntPtr raw) : base(raw) { }

		public Dialog (Widget parent, WindowType f)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_dialog_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		public Dialog (Widget parent, string uiFile, WindowType f = 0)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_dialog_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
			new UiLoader ().Load (this, uiFile);
		}

		#region IDisposable implementation
		protected override void Dispose (bool disposing)
		{
			// free managed resources
			if (disposing)
			{
				qt_dialog_delete (Handle);
			}
			base.Dispose (disposing);
		}

		#endregion

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern int qt_dialog_exec (IntPtr raw);
		public virtual int Exec()
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

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_dialog_accept(IntPtr raw);
		public virtual void Accept()
		{
			qt_dialog_accept (Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_dialog_reject(IntPtr raw);
		public virtual void Reject()
		{
			qt_dialog_reject (Handle);
		}
    }
}

