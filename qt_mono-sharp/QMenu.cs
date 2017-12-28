using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Menu : Widget
	{
		public new event EventHandler<KeyEvent> KeyPressEvent;
		public new event EventHandler<KeyEvent> KeyReleaseEvent;

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_new (Menu thisObject, IntPtr parent);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_menu_delete (IntPtr raw);
		protected Menu (IntPtr raw)
			: base(raw) 
		{
		}

		public Menu (Widget parent = null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_menu_new (this, parent?.Handle ?? IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_title_new (Menu thisObject, string title, IntPtr parent);
		public Menu (string title, Widget parent = null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_menu_title_new (this, title, parent?.Handle ?? IntPtr.Zero);
		}

		#region IDisposable implementation
		~Menu()
		{
			Dispose (false);
		}
		protected override void Dispose (bool disposing)
		{
			// free managed resources
			if (disposing)
			{
				if (Handle != IntPtr.Zero)
				{
					qt_menu_delete (Handle);
					Raw = IntPtr.Zero;
				}
			}
			base.Dispose (disposing);
		}
		private void OnRawDeleted()
		{
			Raw = IntPtr.Zero;
		}
		#endregion

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_seperator_add (IntPtr raw);
		public Action AddSeparator()
		{
			return new Action(qt_menu_seperator_add (Handle));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_action_text_add (IntPtr raw, string text);
		public Action AddAction(string text)
		{
			return new Action(qt_menu_action_text_add (Handle, text));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_action_icon_text_add (IntPtr raw, IntPtr icon, string text);
		public Action AddAction(Icon icon, string text)
		{
			return new Action(qt_menu_action_icon_text_add (Handle, icon.Handle, text));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_exec (IntPtr raw, IntPtr pos, IntPtr action);
		public Action Exec(Point pos, Action at = null)
		{
			var ptr = qt_menu_exec (Handle, pos.Handle, at == null ? IntPtr.Zero : at.Handle);
			return ptr == IntPtr.Zero ? null : new Action (ptr); 
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menu_activeaction_get (IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_menu_activeaction_set (IntPtr raw, IntPtr action);
		public Action ActiveAction
		{
			get
			{
				var ptr = qt_menu_activeaction_get (Handle);
				return ptr == IntPtr.Zero ? null : new Action (ptr);
			}
			set
			{
				qt_menu_activeaction_set (Handle, value == null ? IntPtr.Zero : value.Handle);
			}
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
	}
}

