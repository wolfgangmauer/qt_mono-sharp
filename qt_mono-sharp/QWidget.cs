using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Widget : Object
	{
		public event EventHandler<string> WindowTitleChanged;
		public event EventHandler<Event> BaseEvent;
		public event EventHandler<ShowEvent> ShowEvent;
		public event EventHandler<HideEvent> HideEvent;
		public event EventHandler<Event> EnterEvent;
		public event EventHandler<Event> LeaveEvent;
		public event EventHandler<PaintEvent> PaintEvent;
		public event EventHandler<CloseEvent> CloseEvent;
		public event EventHandler<ResizeEvent> ResizeEvent;
		public event EventHandler<MoveEvent> MoveEvent;
		public event EventHandler<WheelEvent> WheelEvent;
		public event EventHandler<MouseEvent> MousePressEvent;
		public event EventHandler<MouseEvent> MouseReleaseEvent;
		public event EventHandler<MouseEvent> MouseDoubleClickEvent;
		public event EventHandler<MouseEvent> MouseMoveEvent;
		public event EventHandler<KeyEvent> KeyPressEvent;
		public event EventHandler<KeyEvent> KeyReleaseEvent;

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_new (Widget thisObject, IntPtr parent, uint f);

		protected Widget (IntPtr parent) : base(parent)
		{
			if (GetType() != typeof(Widget))
				return;
			Raw = qt_widget_new (this, parent, 0);
		}

		public Widget () : this (null)
		{
		}

		public Widget (Widget parent) : this (parent, 0)
		{
		}

		protected Widget (Widget parent, string uiFile) : base (IntPtr.Zero)
		{
			Raw = new UiLoader (this).Load (uiFile);
			if (parent != null)
				Parent = parent;
		}

		public Widget (Widget parent, WindowType f) : base (IntPtr.Zero)
		{
			if (GetType() != typeof(Widget))
				return;
			Raw = qt_widget_new (this, parent != null ? parent.Handle : IntPtr.Zero, (uint)f);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_layout_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_layout_set (IntPtr raw, IntPtr layout);
		public Layout Layout
		{
			get {
				return (Layout)GetObjectFromRaw(qt_widget_layout_get (Handle));
			}
			set {
				qt_widget_layout_set (Handle, value.Handle);
			}
		}

		public IntPtr LayoutIntPtr
		{
			get {
				return qt_widget_layout_get (Handle);
			}
			set {
				qt_widget_layout_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern uint qt_widget_windowmodality_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowmodality_set (IntPtr raw, uint windowModality);
		public WindowModality WindowModality {
			get {
				return (WindowModality)qt_widget_windowmodality_get (Handle);
			}
			set {
				qt_widget_windowmodality_set (Handle, (uint)value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_show (IntPtr raw);

		public void Show ()
		{
			qt_widget_show (Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_hide (IntPtr raw);

		public void Hide ()
		{
			qt_widget_hide (Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_resize (IntPtr raw, int w, int h);

		public void Resize (int w, int h)
		{
			qt_widget_resize (Handle, w, h);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_sizepolicy_set (IntPtr raw, IntPtr sizePolicy);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_sizepolicy_get (IntPtr raw);

		public SizePolicy SizePolicy {
			get {
				return new SizePolicy (qt_widget_sizepolicy_get (Handle));
			}
			set {
				qt_widget_sizepolicy_set (Handle, value.Handle);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_sizepolicyhv_set (IntPtr raw, Policy horizontal, Policy vertical);

		public void SetSizePolicy (Policy horizontal, Policy vertical)
		{
			qt_widget_sizepolicyhv_set (Handle, horizontal, vertical);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Size qt_widget_minimumsize_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_minimumsize_set (IntPtr raw, int minw, int minh);

		public Size MinimumSize {
			get {
				return qt_widget_minimumsize_get (Handle);
			}
			set {
				SetMinimumSize (value.Width, value.Height);
			}
		}

		public void SetMinimumSize (int minw, int minh)
		{
			qt_widget_minimumsize_set (Handle, minw, minh);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Size qt_widget_maximumsize_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_maximumsize_set (IntPtr raw, int w, int h);

		public Size MaximumSize {
			get {
				return qt_widget_maximumsize_get (Handle);
			}
			set {
				qt_widget_maximumsize_set (Handle, value.Width, value.Height);
			}
		}

		public void SetMaximumSize (int maxw, int maxh)
		{
			qt_widget_maximumsize_set (Handle, maxw, maxh);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern uint qt_widget_focuspolicy_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_focuspolicy_set (IntPtr raw, uint focusPolicy);

		public FocusPolicy FocusPolicy {
			get {
				return (FocusPolicy)qt_widget_focuspolicy_get (Handle);
			}
			set {
				qt_widget_focuspolicy_set (Handle, (uint)value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern uint qt_widget_contextmenupolicy_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_contextmenupolicy_set (IntPtr raw, uint contextMenuPolicy);

		public ContextMenuPolicy ContextMenuPolicy {
			get {
				return (ContextMenuPolicy)qt_widget_contextmenupolicy_get (Handle);
			}
			set {
				qt_widget_contextmenupolicy_set (Handle, (uint)value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern float qt_widget_windowopacity_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowopacity_set (IntPtr raw, double windowopacity);

		public double WindowOpacity {
			get {
				return qt_widget_windowopacity_get (Handle);
			}
			set {
				qt_widget_windowopacity_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern bool qt_widget_autofillbackground_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_autofillbackground_set (IntPtr raw, bool autofillbackground);

		public bool AutoFillBackground {
			get {
				return qt_widget_autofillbackground_get (Handle);
			}
			set {
				qt_widget_autofillbackground_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_stylesheet_set (IntPtr raw, string stylesheet);

		public string StyleSheet {
			set {
				qt_widget_stylesheet_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_font_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_font_set (IntPtr raw, IntPtr font);

		public Font Font {
//            get
//            {
//                return qt_widget_font_get(Handle);
//            }
			set {
				qt_widget_font_set (Handle, value != null ? value.Handle : IntPtr.Zero);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_attribute_set (IntPtr raw, WidgetAttribute attribute);

		public WidgetAttribute Attribute {
			set {
				qt_widget_attribute_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern WindowType qt_widget_windowflags_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowflags_set (IntPtr raw, WindowType windowflags);

		public WindowType WindowFlags {
			get {
				return qt_widget_windowflags_get (Handle);
			}
			set {
				qt_widget_windowflags_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_parent_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_parent_set (IntPtr raw, IntPtr parent);

		public Widget Parent {
			get {
				return GetObjectFromRaw (qt_widget_parent_get (Handle)) as Widget;
			}
			set {
				qt_widget_parent_set (Handle, value != null ? value.Handle : IntPtr.Zero);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern string qt_widget_windowtitle_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowtitle_set (IntPtr raw, string windowtitle);

		public string WindowTitle {
			get {
				return qt_widget_windowtitle_get (Handle);
			}
			set {
				qt_widget_windowtitle_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_fixedsize_set (IntPtr raw, int w, int h);

		public Size FixedSize {
			set
			{
				qt_widget_fixedsize_set (Handle, value.Width, value.Height);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern Rectangle qt_widget_geometry_get (IntPtr raw);

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_geometry_set (IntPtr raw, Rectangle rect);

		public Rectangle Geometry {
			get {
				return qt_widget_geometry_get (Handle);
			}
			set {
				qt_widget_geometry_set (Handle, value);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_adjustsize (IntPtr raw);

		public void AdjustSize ()
		{
			qt_widget_adjustsize (Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_updategeometry (IntPtr raw);

		public void UpdateGeometry ()
		{
			qt_widget_updategeometry (Handle);
		}

		private bool OnShow(ShowEvent ev)
		{
			var tmp = ShowEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnHide(HideEvent ev)
		{
			var tmp = HideEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnEnter(Event ev)
		{
			var tmp = EnterEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnLeave(Event ev)
		{
			var tmp = LeaveEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnPaint(PaintEvent ev)
		{
			var tmp = PaintEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnClose(CloseEvent ev)
		{
			var tmp = CloseEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnResize(ResizeEvent ev)
		{
			var tmp = ResizeEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnMove(MoveEvent ev)
		{
			var tmp = MoveEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnWheel(WheelEvent ev)
		{
			var tmp = WheelEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnMousePress (MouseEvent ev)
		{
			var tmp = MousePressEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnMouseRelease (MouseEvent ev)
		{
			var tmp = MouseReleaseEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnMouseDoubleClick (MouseEvent ev)
		{
			var tmp = MouseDoubleClickEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnMouseMove (MouseEvent ev)
		{
			var tmp = MouseMoveEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnKeyPress (KeyEvent ev)
		{
			var tmp = KeyPressEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private bool OnKeyRelease (KeyEvent ev)
		{
			var tmp = KeyReleaseEvent;
			tmp?.Invoke (this, ev);
			return ev.Accepted;
		}

		private void OnWindowTitleChanged(string title)
		{
			var tmp = WindowTitleChanged;
			tmp?.Invoke (this, title);
		}
	}
}
