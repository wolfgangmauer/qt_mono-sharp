using System;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class StandardItemModel : Object
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_standarditemmodel_new (StandardItemModel thisObject, IntPtr parent);

		public StandardItemModel (Object parent) : base(IntPtr.Zero)
		{
			Raw = qt_standarditemmodel_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_standarditemmodel_rowcount_get (IntPtr handle);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_standarditemmodel_rowcount_set (IntPtr handle, int rows);
		public int RowCount
		{
			get{ return qt_standarditemmodel_rowcount_get (Handle); }
			set{ qt_standarditemmodel_rowcount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_standarditemmodel_columncount_get (IntPtr handle);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_standarditemmodel_columncount_set (IntPtr handle, int columns);
		public int ColumnCount
		{
			get{ return qt_standarditemmodel_columncount_get (Handle); }
			set{ qt_standarditemmodel_columncount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_standarditemmodel_item_row_set (IntPtr handle, int row, IntPtr item);
		public void SetItem(int row, StandardItem item)
		{
			qt_standarditemmodel_item_row_set (Handle, row, item.Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_standarditemmodel_item_row_column_set (IntPtr handle, int row, int col, IntPtr item);
		public void SetItem(int row, int col, StandardItem item)
		{
			qt_standarditemmodel_item_row_column_set (Handle, row, col, item.Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_standarditemmodel_item_append (IntPtr handle, IntPtr item);
		public void AppendRow(StandardItem item)
		{
			qt_standarditemmodel_item_append (Handle, item.Handle);
		}
	}
}

