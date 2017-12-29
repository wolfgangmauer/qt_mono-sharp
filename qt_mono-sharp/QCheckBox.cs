using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public class CheckBox : AbstractButton
	{
		public CheckBox (IntPtr raw) : base(raw) {}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_checkbox_new_with_text (CheckBox thisObject, string text, IntPtr parent);
		public CheckBox (string text, Widget parent=null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_checkbox_new_with_text (this, text, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_checkbox_new (CheckBox thisObject, IntPtr parent);
		public CheckBox (Widget parent)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_checkbox_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_checkbox_sizehint_get (IntPtr raw);
		public new Size SizeHint
		{
			get{ return new Size(qt_checkbox_sizehint_get(Handle));}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern bool qt_checkbox_tristate_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_checkbox_tristate_set(IntPtr raw, bool tristate);
		public bool Tristate
		{
			get
			{
				return qt_checkbox_tristate_get(Handle);
			}
			set
			{
				qt_checkbox_tristate_set(Handle, value);
			}
		}
	}
}

