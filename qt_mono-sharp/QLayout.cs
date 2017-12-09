using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;

namespace Qt
{
	public class Layout : Object
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_layout_new (Object thisObject, IntPtr parent);

		protected Layout () { }

		protected Layout (IntPtr raw) : base (raw) { }

		public Layout (Object parent = null) : base (IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_layout_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_layout_parent_get (IntPtr raw);

		public Widget Parent {
			get {
				return GetObjectFromRaw (qt_layout_parent_get (Handle)) as Widget;
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_layout_spacing_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_spacing_set (IntPtr raw, int spacing);

		public int Spacing {
			get {
				return qt_layout_spacing_get (Handle);
			}
			set {
				qt_layout_spacing_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_layout_margin_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_margin_set (IntPtr raw, int margin);

		public int Margin {
			get {
				return qt_layout_margin_get (Handle);
			}
			set {
				qt_layout_margin_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern SizeConstraint qt_layout_sizeconstraint_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_sizeconstraint_set (IntPtr raw, SizeConstraint sizeConstraint);

		public SizeConstraint SizeConstraint {
			get {
				return qt_layout_sizeconstraint_get (Handle);
			}
			set {
				qt_layout_sizeconstraint_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_contentsmargins_set (IntPtr raw, int left, int top, int right, int bottom);

		public void SetContentsMargins (int left, int top, int right, int bottom)
		{
			qt_layout_contentsmargins_set (Handle, left, top, right, bottom);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_contentsmargins_get (IntPtr raw, ref int left, ref int top, ref int right, ref int bottom);

		public void GetContentsMargins (ref int left, ref int top, ref int right, ref int bottom)
		{
			qt_layout_contentsmargins_get (Handle, ref left, ref top, ref right, ref bottom);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Rectangle qt_layout_geometry_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_geometry_set (IntPtr raw, Rectangle rect);

		public Rectangle Geometry {
			get {
				return qt_layout_geometry_get (Handle);
			}
			set {
				qt_layout_geometry_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_layout_widget_add (IntPtr raw, IntPtr widget);

		public void AddWidget (Widget widget)
		{
			qt_layout_widget_add (Handle, widget.Handle);
		}

		public virtual bool HasLayout { get; protected set; }

		public int LeftMargin { get; set; } = -1;

		public int RightMargin { get; set; } = -1;

		public int TopMargin { get; set; } = -1;

		public int BottomMargin { get; set; } = -1;
	}
}

