using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public class Label : Frame
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_label_new (Label thisObject, IntPtr parent, WindowType f);

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_label_new_with_text (Label thisObject, string text, IntPtr parent, WindowType f);

		private Label (IntPtr parent) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(Label))
				return;
			Raw = qt_label_new (this, parent, 0);
		}

		public Label () : this(null, 0) {}

		public Label (Widget parent) : this(parent, 0) {}

		public Label (Widget parent, string text, WindowType f = 0) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(Label))
				return;
			Raw = qt_label_new_with_text (this, text, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		public Label (Widget parent, WindowType f = 0) : base(IntPtr.Zero)
		{
			if (GetType () != typeof(Label))
				return;
			Raw = qt_label_new (this, parent != null ? parent.Handle : IntPtr.Zero, f);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_label_text_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_label_text_set(IntPtr raw, string alignment);
		public string Text
		{
			get
			{
				return qt_label_text_get(Handle);
			}
			set
			{
				qt_label_text_set(Handle, value);
			}
		}

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern Alignment qt_label_alignment_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_label_alignment_set(IntPtr raw, Alignment alignment);
		[XmlIgnore]
        public Alignment Alignment
        {
            get
            {
                return qt_label_alignment_get(Handle);
            }
            set
            {
                qt_label_alignment_set(Handle, value);
            }
        }

		[XmlAttribute("stringAlignment")]
		private string stringAlignment
		{
			get
			{
				return Alignment.ToString();
			}
			set
			{
				Alignment alignment = default(Alignment);
				var s = value;
				var strenums = s.Split (new[]{ '|' });
				foreach (var strenum in strenums)
				{
					alignment |= (Alignment)Alignment.Parse (typeof(Alignment), strenum.Replace("Qt::", ""));
				}
				Alignment = alignment;
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern TextInteractionFlags qt_label_textinteractionflags_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_label_textinteractionflags_set(IntPtr raw, TextInteractionFlags flag);
		public TextInteractionFlags TextInteractionFlags
		{
			get
			{
				return qt_label_textinteractionflags_get(Handle);
			}
			set
			{
				qt_label_textinteractionflags_set(Handle, value);
			}
		}

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_label_indent_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_label_indent_set(IntPtr raw, int indent);
        public int Indent
        {
            get
            {
                return qt_label_indent_get(Handle);
            }
            set
            {
                qt_label_indent_set(Handle, value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern TextFormat qt_label_textformat_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_label_textformat_set(IntPtr raw, TextFormat format);
		public TextFormat TextFormat
		{
			get
			{
				return qt_label_textformat_get(Handle);
			}
			set
			{
				qt_label_textformat_set(Handle, value);
			}
		}

		public bool ScaledContents{
			get;
			set;
		}

		public bool WordWrap{
			get;
			set;
		}
    }
}

