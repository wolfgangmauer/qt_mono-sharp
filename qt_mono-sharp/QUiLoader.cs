using System;
using System.Runtime.CompilerServices;
using System.Linq;
using System.Reflection;

namespace Qt
{
	public class UiLoader : Object
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_uiloader_new (UiLoader thisObject, IntPtr parent);

		protected UiLoader (IntPtr raw) : base(raw) {}

        Widget _parent; 
		bool firstWidget;
		public UiLoader (Widget parent) : base(IntPtr.Zero)
		{
            _parent = parent;
			Raw = qt_uiloader_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_uiloader_load (IntPtr handle, string uiFile, IntPtr parentWidget);
		public IntPtr Load(string uiFile)
		{
			firstWidget = true;
			var retVal = qt_uiloader_load (Handle, uiFile, _parent.Handle);
			if (retVal != IntPtr.Zero)
			{
				if (_parent != null) {
					var fields4Loader = _parent.GetType ().GetFields (BindingFlags.NonPublic | BindingFlags.Instance).Where (field => field.IsDefined (typeof(UiLoaderAttribute), false));
					foreach (var field in fields4Loader) {
						var fieldAttribute = (UiLoaderAttribute)field.GetCustomAttribute (typeof(UiLoaderAttribute));
						var fieldAttrName = fieldAttribute.FieldName;
						if (string.IsNullOrWhiteSpace (fieldAttrName))
							fieldAttrName = field.Name;
						var rawObject = FindRawObject (retVal, fieldAttrName);
						if (rawObject != IntPtr.Zero) {
							field.SetValue (_parent, GetObjectFromRaw (rawObject)); //Activator.CreateInstance (field.FieldType, BindingFlags.CreateInstance | BindingFlags.NonPublic | BindingFlags.Instance, null, new object[] { rawObject }, null));
						}
					}
				}
			}
			return retVal;
		}

		protected IntPtr OnCreateLayout(string className, IntPtr parent, string objectName)
		{
			var retVal = IntPtr.Zero;
			var t = Type.GetType ("Qt." + className.Substring (1));
			if (t == null)
				return IntPtr.Zero;
			var obj = Activator.CreateInstance (t, BindingFlags.CreateInstance | BindingFlags.NonPublic | BindingFlags.Instance, null, new object[] { parent }, null) as Object;
			obj.ObjectName = objectName;
			retVal = obj.Handle;
			return retVal;
		}

		protected IntPtr OnCreateWidget(string className, IntPtr parent, string objectName)
		{
			var retVal = IntPtr.Zero;
			var t = Type.GetType ("Qt." + className.Substring (1));
			if (t == null)
				return IntPtr.Zero;
			Object obj = null;
			if (firstWidget)
			{
				obj = GetObjectFromName (objectName);
				firstWidget = false;
			}
			if (obj == null)
				obj = Activator.CreateInstance (t, BindingFlags.CreateInstance | BindingFlags.NonPublic | BindingFlags.Instance, null, new object[] { parent }, null) as Widget;
			obj.ObjectName = objectName;
			retVal = obj.Handle;
			return retVal;
		}
	}
}

