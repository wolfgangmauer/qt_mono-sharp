﻿using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
    public class TableWidget : TableView
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tablewidget_new(TableWidget thisObject, IntPtr parent);

		protected TableWidget () { }

		protected TableWidget (IntPtr raw) : base(raw) { }

		public TableWidget(Widget parent)
        {
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_tablewidget_new(this, parent != null ? parent.Handle : IntPtr.Zero);
        }

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_tablewidget_rowcount_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tablewidget_rowcount_set (IntPtr parent, int rows);
		public int RowCount
		{
			get{ return qt_tablewidget_rowcount_get (Handle); }
			set{ qt_tablewidget_rowcount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_tablewidget_colcount_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tablewidget_colcount_set (IntPtr parent, int cols);
		public int ColumnCount
		{
			get{ return qt_tablewidget_colcount_get (Handle); }
			set{ qt_tablewidget_colcount_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tablewidget_row_col_set (IntPtr handle, int row, int col, IntPtr item);
		public void SetItem(int row, int col, TableWidgetItem item)
		{
			qt_tablewidget_row_col_set (Handle, row, col, item.Handle);
		}
    }
}
