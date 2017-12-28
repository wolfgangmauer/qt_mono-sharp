using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Action : Object
	{
		public event EventHandler<bool> TriggerEvent;

		public Action (IntPtr raw) : base(raw) { }

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_action_new(Action thisObject, IntPtr parent);
		public Action(Object parent = null)
			: base(IntPtr.Zero)
		{
			Raw = qt_action_new (this, parent == null ? IntPtr.Zero : parent.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern IntPtr qt_action_text_new(Action thisObject, string text, IntPtr parent);
		public Action(string text, Object parent = null)
			: base(IntPtr.Zero)
		{
			Raw = qt_action_text_new (this, text, parent == null ? IntPtr.Zero : parent.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern string qt_action_text_get(IntPtr raw);
		[MethodImpl(MethodImplOptions.InternalCall)]
		private static extern void qt_action_text_set(IntPtr raw, string text);
		public string Text
		{
			get
			{
				return qt_action_text_get (Raw);
			}
			set
			{
				qt_action_text_set(Handle, value);
			}
		}

		public static bool operator== (Action obj1, Action obj2)
		{
			if (ReferenceEquals(obj1, obj2))
			{
				return true;
			}
			if (ReferenceEquals(obj1, null))
			{
				return false;
			}
			if (ReferenceEquals(obj2, null))
			{
				return false;
			}
			return (obj1.Handle == obj2.Handle);
		}

		public static bool operator!= (Action obj1, Action obj2)
		{
			return !(obj1 == obj2);
		}

		public override bool Equals(object obj)
		{
			if (ReferenceEquals(null, obj))
			{
				return false;
			}
			if (ReferenceEquals(this, obj))
			{
				return true;
			}
			return (((Action)obj).Handle == Handle);
		}

		public override int GetHashCode()
		{
			return Handle.GetHashCode ();
		}

		private void OnTriggered (bool _checked)
		{
			var tmp = TriggerEvent;
			tmp?.Invoke (this, _checked);
		}
	}
}

