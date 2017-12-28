using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ListWidget : ListView
	{
		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_listwidget_new(ListWidget thisObject, IntPtr parent);

		public ListWidget (Widget parent)
			: base(IntPtr.Zero)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_listwidget_new(this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_listwidget_item_add (IntPtr raw, IntPtr item);
		public void AppendItem(ListWidgetItem item)
		{
			qt_listwidget_item_add (Handle, item.Handle);
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_listwidget_item_get (IntPtr raw, int row);
		public ListWidgetItem Item(int row)
		{
			return new ListWidgetItem(qt_listwidget_item_get(Handle, row));
		}

		[MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern void qt_listwidget_item_select (IntPtr raw, IntPtr item, bool _select);
		public void SetItemSelected(ListWidgetItem item, bool _select)
		{
			qt_listwidget_item_select (Handle, item.Handle, _select);
		}
	}
}

