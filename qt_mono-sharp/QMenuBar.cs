using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class MenuBar : Widget
	{
		public new event EventHandler<KeyEvent> KeyPressEvent;
		public new event EventHandler<KeyEvent> KeyReleaseEvent;
		public event EventHandler<Action> TriggerEvent;
		public event EventHandler<Action> HoveredEvent;

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menubar_new (MenuBar thisObject, IntPtr parent);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_menubar_delete (IntPtr raw);

		public MenuBar (IntPtr raw) :base(raw){}

		public MenuBar (Widget parent = null)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_menubar_new (this, parent?.Handle ?? IntPtr.Zero);
		}

		#region IDisposable implementation
		~MenuBar()
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
					qt_menubar_delete (Handle);
					Raw = IntPtr.Zero;
				}
			}
			base.Dispose (disposing);
		}
		#endregion

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menubar_action_text_add (IntPtr raw, string text);
		public Action AddAction(string text)
		{
			return new Action(qt_menubar_action_text_add (Handle, text));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_menubar_activeaction_get (IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_menubar_activeaction_set (IntPtr raw, IntPtr action);
		public Action ActiveAction
		{
			get
			{
				var ptr = qt_menubar_activeaction_get (Handle);
				return ptr == IntPtr.Zero ? null : new Action (ptr);
			}
			set
			{
				qt_menubar_activeaction_set (Handle, value == null ? IntPtr.Zero : value.Handle);
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

		private void OnTriggered (IntPtr action)
		{
			var acObj = GetObjectFromRaw (action) as Action;
			if (acObj == null)
				acObj = new Action (action);
			var tmp = TriggerEvent;
			tmp?.Invoke (this, acObj);
		}

		private void OnHovered (IntPtr action)
		{
			var acObj = GetObjectFromRaw (action) as Action;
			if (acObj == null)
				acObj = new Action (action);
			var tmp = HoveredEvent;
			tmp?.Invoke (this, acObj);
		}
	}
}

