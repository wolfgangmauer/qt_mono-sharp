using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public enum Shadow
	{
		[XmlEnum("QFrame::Plain")]
		Plain = 0x0010, // plain line
		[XmlEnum("QFrame::Raised")]
		Raised = 0x0020, // raised shadow effect
		[XmlEnum("QFrame::Sunken")]
		Sunken = 0x0030 // sunken shadow effect
	}

	public enum Shape
	{
		[XmlEnum("QFrame::NoFrame")]
		NoFrame = 0, // no frame
		[XmlEnum("QFrame::Box")]
		Box = 0x0001, // rectangular box
		[XmlEnum("QFrame::Panel")]
		Panel = 0x0002, // rectangular panel
		[XmlEnum("QFrame::WinPanel")]
		WinPanel = 0x0003, // rectangular panel (Windows)
		[XmlEnum("QFrame::HLine")]
		HLine = 0x0004, // horizontal line
		[XmlEnum("QFrame::VLine")]
		VLine = 0x0005, // vertical line
		[XmlEnum("QFrame::StyledPanel")]
		StyledPanel = 0x0006 // rectangular panel depending on the GUI style
	}

	public partial class Frame : Widget
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_frame_new (Frame thisObject, IntPtr parent);

		protected Frame (IntPtr raw) : base(raw) {}

		public Frame () : this(null) {}

		public Frame (Widget parent) : base(IntPtr.Zero)
		{
			Raw = qt_frame_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern Shape qt_frame_shape_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_frame_shape_set(IntPtr raw, Shape frameshape);
		public Shape FrameShape
		{
			get
			{
				return qt_frame_shape_get(Handle);
			}
			set
			{
				qt_frame_shape_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern Shadow qt_frame_shadow_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_frame_shadow_set(IntPtr raw, Shadow frameshadow);
		public Shadow FrameShadow
        {
            get
            {
                return qt_frame_shadow_get(Handle);
            }
            set
            {
				qt_frame_shadow_set(Handle, value);
            }
        }


        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_frame_linewidth_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_frame_linewidth_set(IntPtr raw, int linewidth);
        public int LineWidth
        {
            get
            {
				return qt_frame_linewidth_get(Handle);
            }
            set
            {
				qt_frame_linewidth_set(Handle, value);
            }
        }
    }
}

