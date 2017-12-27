using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class TableWidgetItem
	{
		public IntPtr Handle { get ; private set; }

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tablewidgetitem_new (string text);
		public TableWidgetItem (string text)
		{
			Handle = qt_tablewidgetitem_new (text);
		}

		public TableWidgetItem(IntPtr raw)
		{
			Handle = raw;
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern string qt_tablewidgetitem_text_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tablewidgetitem_text_set (IntPtr raw, string text);
		public string Text
		{
			get{
				return qt_tablewidgetitem_text_get (Handle);
			}
			set{
				qt_tablewidgetitem_text_set (Handle, value);
			}
		}
	}
}

