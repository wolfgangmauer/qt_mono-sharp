using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Linq;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class Object : IDisposable
	{
		IntPtr handle;
		static Dictionary<IntPtr, Object> objects = new Dictionary<IntPtr, Object> ();

		public event EventHandler DisposedEvent;

		protected Object ()
		{
		}

		public Object (Object parent)
		{
			CreateNativeObject ();
		}

		public Object (IntPtr raw)
		{
			Raw = raw;
		}

		#region IDisposable implementation

		public void Dispose ()
		{
			Dispose (true);
			GC.SuppressFinalize (this);
		}

		public bool IsDisposed;

		protected virtual void Dispose (bool disposing)
		{
			// free managed resources
			if (disposing) {
			}
			IsDisposed = true;
			var tmp = DisposedEvent;
			tmp?.Invoke (this, new System.EventArgs ());
		}

		#endregion

		public IntPtr Handle {
			get {
				return handle;
			}
		}

		protected virtual IntPtr Raw {
			get {
				return handle;
			}
			set {
				if (handle == value)
					return;
				lock (objects) {
					if (handle != IntPtr.Zero) {
						objects.Remove (handle);
					}
					handle = value;
					if (handle != IntPtr.Zero) {
						objects [handle] = this;
						if (string.IsNullOrWhiteSpace (ObjectName))
							ObjectName = GetType ().Name;
					}
				}
			}
		}

		protected object GetManangedObject ()
		{
			return this;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_native_delegate_set (IntPtr raw, Delegate method);

		protected virtual void CreateNativeObject (Delegate method = null)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_object_find (IntPtr raw, string objectName);

		public static IntPtr FindRawObject (IntPtr raw, string objectName)
		{
			return qt_object_find (raw, objectName);
		}

		static public Object GetObjectFromRaw (IntPtr raw)
		{
			if (objects.ContainsKey (raw))
				return objects [raw];
			return null;
		}

		static protected Object GetObjectFromName (string name)
		{
			var obj = objects.Values.FirstOrDefault (o => o.ObjectName.Equals (name));
			return obj;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		extern static string qt_objectname_get (IntPtr handle);

		[MethodImpl (MethodImplOptions.InternalCall)]
		extern static void qt_objectname_set (IntPtr handle, string name);

		public string ObjectName {
			get {
				if (Handle == IntPtr.Zero)
					throw new ArgumentNullException ();
				return qt_objectname_get (Handle);
			}
			set {
				qt_objectname_set (Handle, value);
			}
		}
	}
}

