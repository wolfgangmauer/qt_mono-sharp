using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ItemModel : Object
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_itemmodel_new (ItemModel thisObject, IntPtr parent);

		public ItemModel (Object parent) : base(IntPtr.Zero)
		{
			Raw = qt_itemmodel_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_itemmodel_rowcount_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemmodel_rowcount_set (IntPtr parent, int rows);
		public int RowCount
		{
			get{ return qt_itemmodel_rowcount_get (Handle); }
			set{ qt_itemmodel_rowcount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_itemmodel_columncount_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemmodel_columncount_set (IntPtr parent, int columns);
		public int ColumnCount
		{
			get{ return qt_itemmodel_columncount_get (Handle); }
			set{ qt_itemmodel_columncount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemmodel_item_row_set (IntPtr parent, int row, IntPtr item);
		public void SetItem(int row, StandardItem item)
		{
			qt_itemmodel_item_row_set (Handle, row, item.Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemmodel_item_row_column_set (IntPtr handle, int row, int column, IntPtr item);
		public void SetItem(int row, int column, StandardItem item)
		{
			qt_itemmodel_item_row_column_set (Handle, row, column, item.Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemmodel_item_append (IntPtr handle, IntPtr item);
		public void AppendRow(StandardItem item)
		{
			qt_itemmodel_item_append (Handle, item.Handle);
		}
	}
}

