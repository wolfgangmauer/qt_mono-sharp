using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class BoxLayout : Layout
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_boxlayout_new (BoxLayout thisObject, Direction dir, IntPtr parent);

		protected BoxLayout (IntPtr raw) : base(raw) {}

		public BoxLayout (Direction dir, Widget parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_boxlayout_new (this, dir, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_boxlayout_widget_add (IntPtr raw, IntPtr widget, int strech, Qt.Alignment alignment);
		public virtual void AddWidget(Widget widget, int stretch = 0, Qt.Alignment alignment = 0)
		{
			qt_boxlayout_widget_add (Handle, widget.Handle, stretch, alignment);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_boxlayout_layout_add (IntPtr raw, IntPtr widget, int strech);
		public virtual void AddLayout (Layout widget, int stretch = 0)
		{
			qt_boxlayout_layout_add (Handle, widget.Handle, stretch);
		}

		public void AddLayout(IntPtr widget, int stretch = 0)
		{
			qt_boxlayout_layout_add (Handle, widget, stretch);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern Direction qt_boxlayout_direction_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_boxlayout_direction_set(IntPtr raw, Direction direction);
		public Direction Direction
		{
			get
			{
				return qt_boxlayout_direction_get(Handle);
			}
			set
			{
				qt_boxlayout_direction_set(Handle, value);
			}
		}
	}
}

