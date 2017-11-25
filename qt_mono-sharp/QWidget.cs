using System;
using System.Runtime.InteropServices;
using System.Text;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Widget : Object
	{
		public event EventHandler<KeyEventArgs> KeyPressEvent;
		public event EventHandler<KeyEventArgs> KeyReleaseEvent;

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_new (Widget thisObject, IntPtr parent, uint f);

		internal Widget (IntPtr raw) : base(raw) {}

		public Widget () : this (null) {}

		public Widget (Widget parent) : this (parent, 0) {}

		public Widget (Widget parent, WindowType f) : base(IntPtr.Zero)
		{
			Raw = qt_widget_new (this, parent != null ? parent.Handle : IntPtr.Zero, (uint)f);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern uint qt_widget_windowmodality_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowmodality_set(IntPtr raw, uint windowModality);
        public WindowModality WindowModality
        {
            get
            {
				return (WindowModality)qt_widget_windowmodality_get(Handle);
            }
            set
            {
				qt_widget_windowmodality_set(Handle, (uint)value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_show(IntPtr raw);
		public virtual void Show()
		{
			//var handle = GetObjectFromRaw (Handle);
			qt_widget_show(Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_hide(IntPtr raw);
		public void Hide()
		{
			qt_widget_hide(Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_resize(IntPtr raw, int w, int h);
        public void Resize(int w, int h)
        {
            qt_widget_resize(Handle, w, h);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_sizepolicy_set(IntPtr raw, IntPtr sizePolicy);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_sizepolicy_get(IntPtr raw);
		public SizePolicy SizePolicy
        {
            get
            {
				return new SizePolicy(qt_widget_sizepolicy_get (Handle));
            }
            set
            {
                qt_widget_sizepolicy_set(Handle, value.Handle);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_sizepolicyhv_set(IntPtr raw, Policy horizontal, Policy vertical);
		public void SetSizePolicy(Policy horizontal, Policy vertical)
        {
			qt_widget_sizepolicyhv_set(Handle, horizontal, vertical);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_minimumsize_get(IntPtr raw, ref int w, ref int h);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_minimumsize_set(IntPtr raw, int w, int h);
        public Size MinimumSize
        {
            get
            {
				int w = 0, h = 0;
				qt_widget_minimumsize_get(Handle, ref w, ref h);
				return new Size (w, h);
            }
            set
            {
				qt_widget_minimumsize_set(Handle, value.Width, value.Height);
            }
        }

        public void SetMinimumSize(int minw, int minh)
        {
            qt_widget_minimumsize_set(Handle, minw, minh);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_maximumsize_get(IntPtr raw, ref int w, ref int h);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_maximumsize_set(IntPtr raw, int w, int h);
        public Size MaximumSize
        {
            get
            {
				int w = 16777215, h = 16777215;
				qt_widget_maximumsize_get(Handle, ref w, ref h);
				return new Size (w, h);
            }
            set
            {
				qt_widget_maximumsize_set(Handle, value.Width, value.Height);
            }
		}

        public void SetMaximumSize(int maxw, int maxh)
        {
            qt_widget_maximumsize_set(Handle, maxw, maxh);
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern uint qt_widget_focuspolicy_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_focuspolicy_set(IntPtr raw, uint focusPolicy);
        public FocusPolicy FocusPolicy
        {
            get
            {
				return (FocusPolicy)qt_widget_focuspolicy_get(Handle);
            }
            set
            {
				qt_widget_focuspolicy_set(Handle, (uint)value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern uint qt_widget_contextmenupolicy_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_contextmenupolicy_set(IntPtr raw, uint contextMenuPolicy);
        public ContextMenuPolicy ContextMenuPolicy
        {
            get
            {
				return (ContextMenuPolicy)qt_widget_contextmenupolicy_get(Handle);
            }
            set
            {
				qt_widget_contextmenupolicy_set(Handle, (uint)value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern float qt_widget_windowopacity_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowopacity_set(IntPtr raw, double windowopacity);
        public double WindowOpacity
        {
            get
            {
                return qt_widget_windowopacity_get(Handle);
            }
            set
            {
                qt_widget_windowopacity_set(Handle, value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern bool qt_widget_autofillbackground_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_autofillbackground_set(IntPtr raw, bool autofillbackground);
        public bool AutoFillBackground
        {
            get
            {
                return qt_widget_autofillbackground_get(Handle);
            }
            set
            {
                qt_widget_autofillbackground_set(Handle, value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_stylesheet_set(IntPtr raw, string stylesheet);
        public string StyleSheet
        {
            set
            {
                qt_widget_stylesheet_set(Handle, value);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_font_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
        protected static extern void qt_widget_font_set(IntPtr raw, IntPtr font);
        public Font Font
        {
//            get
//            {
//                return qt_widget_font_get(Handle);
//            }
            set
            {
				qt_widget_font_set(Handle, value.Handle);
            }
        }

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_attribute_set(IntPtr raw, WidgetAttribute attribute);
		public WidgetAttribute Attribute
		{
			set
			{
				qt_widget_attribute_set (Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern WindowType qt_widget_windowflags_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowflags_set(IntPtr raw, WindowType windowflags);
		public WindowType WindowFlags
		{
			get
			{
				return qt_widget_windowflags_get(Handle);
			}
			set
			{
				qt_widget_windowflags_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_parent_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_parent_set(IntPtr raw, IntPtr parent);
		public Widget Parent
		{
			get
			{
				return GetObjectFromRaw(qt_widget_parent_get(Handle)) as Widget;
			}
			set
			{
				qt_widget_parent_set(Handle, value.Handle);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern string qt_widget_windowtitle_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_windowtitle_set(IntPtr raw, string windowtitle);
		public string WindowTitle
		{
			get
			{
				return qt_widget_windowtitle_get(Handle);
			}
			set
			{
				qt_widget_windowtitle_set(Handle, value);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_fixedsize_set(IntPtr raw, int w, int h);
		public Size FixedSize
		{
			set
			{
				qt_widget_fixedsize_set(Handle, value.Width, value.Height);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_geometry_get(IntPtr raw, ref int x, ref int y, ref int width, ref int height);
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_geometry_set(IntPtr raw, int x, int y, int width, int height);
		public Rect Geometry
		{
			get
			{
				int x = 0, y = 0, width = 0, height = 0;
				qt_widget_geometry_get (Handle, ref x, ref y, ref width, ref height);
				return new Rect (x, y, width, height);
			}
			set
			{
				qt_widget_geometry_set (Handle, value.X, value.Y, value.Width, value.Height);
			}
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_adjustsize(IntPtr raw);
		public void AdjustSize()
		{
			qt_widget_adjustsize(Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_widget_updategeometry(IntPtr raw);
		public void UpdateGeometry()
		{
			qt_widget_updategeometry (Handle);
		}

		protected int KeyPress (KeyEventArgs args)
		{
			var tmp = KeyPressEvent;
			tmp?.Invoke (this, args);
			return -1;
		}

		protected int KeyRelease(KeyEventArgs args)
		{
			var tmp = KeyReleaseEvent;
			tmp?.Invoke (this, args);
			return -1;
		}
    }
}

