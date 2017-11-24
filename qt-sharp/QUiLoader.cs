using System;
using System.Runtime.CompilerServices;
using System.Linq;
using System.Reflection;

namespace Qt
{
	public class UiLoader : Object
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_uiloader_new (Object thisObject, IntPtr parent);

		protected UiLoader (IntPtr raw) : base(raw) {}

		public UiLoader (Object parent = null) : base(IntPtr.Zero)
		{
			Raw = qt_uiloader_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_uiloader_load (IntPtr handle, string uiFile, IntPtr parentWidget);
		public IntPtr Load(string uiFile, Widget parentWidget = null)
		{
			var retVal = qt_uiloader_load (Handle, uiFile, parentWidget != null ? parentWidget.Handle : IntPtr.Zero);			
			if (parentWidget != null)
			{
				var fields4Loader = parentWidget.GetType().GetFields(BindingFlags.NonPublic| BindingFlags.Instance).Where(field => field.IsDefined(typeof(UiLoaderAttribute), false));
				foreach (var field in fields4Loader)
				{
					var fieldAttribute = (UiLoaderAttribute)field.GetCustomAttribute (typeof(UiLoaderAttribute));
					var fieldAttrName = fieldAttribute.FieldName;
					if (string.IsNullOrWhiteSpace (fieldAttrName))
						fieldAttrName = field.Name;
					var rawObject = FindRawObject (retVal, fieldAttrName);
					if (rawObject != IntPtr.Zero)
					{
						field.SetValue (parentWidget, Activator.CreateInstance (field.FieldType, BindingFlags.CreateInstance | BindingFlags.NonPublic | BindingFlags.Instance, null, new object[] { rawObject }, null));
					}
				}
			}
			return retVal;
		}
	}
}

