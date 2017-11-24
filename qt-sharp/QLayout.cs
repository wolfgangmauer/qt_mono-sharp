using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public class Layout : Object
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_layout_new (Object thisObject, IntPtr parent);

		protected Layout (IntPtr raw) : base(raw) {}

		public Layout (Object parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_layout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_layout_parent_get(IntPtr raw);
		public Widget Parent
		{
			get
			{
				return GetObjectFromRaw(qt_layout_parent_get(Handle)) as Widget;
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_layout_spacing_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_layout_spacing_set(IntPtr raw, int spacing);
        public int Spacing
        {
            get
            {
                return qt_layout_spacing_get(Handle);
            }
            set
            {
                qt_layout_spacing_set(Handle, value);
            }
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern int qt_layout_margin_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_layout_margin_set(IntPtr raw, int margin);
        public int Margin
        {
            get
            {
                return qt_layout_margin_get(Handle);
            }
            set
            {
                qt_layout_margin_set(Handle, value);
            }
        }
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern SizeConstraint qt_layout_sizeconstraint_get(IntPtr raw);
        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_layout_sizeconstraint_set(IntPtr raw, SizeConstraint sizeConstraint);
        public SizeConstraint SizeConstraint
        {
            get
            {
                return qt_layout_sizeconstraint_get(Handle);
            }
            set
            {
                qt_layout_sizeconstraint_set(Handle, value);
            }
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_layout_contentsmargins_set(IntPtr raw, int left, int top, int right, int bottom);
        public void SetContentsMargins(int left, int top, int right, int bottom)
        {
            qt_layout_contentsmargins_set(Handle, left, top, right, bottom);
        }

        [MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_layout_contentsmargins_get(IntPtr raw, ref int left, ref int top, ref int right, ref int bottom);
        public void GetContentsMargins(ref int left, ref int top, ref int right, ref int bottom)
        {
            qt_layout_contentsmargins_get(Handle, ref left, ref top, ref right, ref bottom);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_geometry_get(IntPtr raw, ref int x, ref int y, ref int width, ref int height);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_geometry_set(IntPtr raw, int x, int y, int width, int height);
		public Rect Geometry
		{
			get
			{
				int x = 0, y = 0, width = 0, height = 0;
				qt_layout_geometry_get (Handle, ref x, ref y, ref width, ref height);
				return new Rect (x, y, width, height);
			}
			set
			{
				qt_layout_geometry_set (Handle, value.X, value.Y, value.Width, value.Height);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_widget_add (IntPtr raw, IntPtr widget);
		public virtual void AddWidget(Widget widget)
		{
			qt_layout_widget_add (Handle, widget.Handle);
		}

		public virtual void AddLayout(Layout widget, int stretch = 0)
		{
			HasLayout = true;
		}

		public virtual bool HasLayout { get; protected set; }

		public int LeftMargin { get; set; } = -1;
		public int RightMargin { get; set; } = -1;
		public int TopMargin { get; set; } = -1;
		public int BottomMargin { get; set; } = -1;
    }
}

