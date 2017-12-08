using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class TableWidgetItem
	{
		IntPtr raw;

		public IntPtr Handle { get { return raw; }}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tablewidgetitem_new (string text);
		public TableWidgetItem (string text)
		{
			raw = qt_tablewidgetitem_new (text);
		}
	}
}

