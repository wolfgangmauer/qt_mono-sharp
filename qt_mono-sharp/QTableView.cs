using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class TableView : ItemView
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tableview_new (TableView thisObject, IntPtr parent);

		protected TableView () { }

		protected TableView (IntPtr raw) : base(raw) { }

		public TableView (Widget parent)
		{
			if (Raw != IntPtr.Zero)
				throw new ArgumentException ("Raw not null!");
			Raw = qt_tableview_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tableview_horizontalheader_get (IntPtr raw);
		public HeaderView HorizontalHeader {
			get {
				HeaderView retVal = null;
				var raw = qt_tableview_horizontalheader_get (Handle);
				retVal = GetObjectFromRaw (raw) as HeaderView;
				if (retVal == null)
					retVal = new HeaderView (raw);
				return retVal;
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tableview_verticalheader_get (IntPtr raw);
		public HeaderView VerticalHeader {
			get
			{
				HeaderView retVal = null;
				var raw = qt_tableview_verticalheader_get (Handle);
				retVal = GetObjectFromRaw (raw) as HeaderView;
				if (retVal == null)
					retVal = new HeaderView (raw);
				return retVal;
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_selectrow (IntPtr raw, int row);
		public void SelectRow (int row)
		{
			qt_tableview_selectrow (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_tableview_columnwidth_get (IntPtr raw, int column);
		public int GetColumnWidth(int column)
		{
			return qt_tableview_columnwidth_get (Handle, column);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_columnwidth_set (IntPtr raw, int column, int width);
		public void SetColumnWidth(int column, int width)
		{
			qt_tableview_columnwidth_set (Handle, column, width);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_selectcolumn (IntPtr raw, int column);
		public void SelectColumn (int column)
		{
			qt_tableview_selectcolumn (Handle, column);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_hiderow (IntPtr raw, int column);
		public void HideRow (int row)
		{
			qt_tableview_hiderow (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_showrow (IntPtr raw, int column);
		public void ShowRow (int row)
		{
			qt_tableview_showrow (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_hidecolumn (IntPtr raw, int column);
		public void HideColumn (int column)
		{
			qt_tableview_hidecolumn (Handle, column);
		}


		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_showcolumn (IntPtr raw, int column);
		public void ShowColumn (int column)
		{
			qt_tableview_showcolumn (Handle, column);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_resizerowtocontents (IntPtr raw, int row);
		public void ResizeRowToContents (int row)
		{
			qt_tableview_resizerowtocontents (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_resizerowstocontents (IntPtr raw);
		public void ResizeRowsToContents ()
		{
			qt_tableview_resizerowstocontents (Handle);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_resizecolumntocontents (IntPtr raw, int column);
		public void ResizeColumnToContents (int column)
		{
			qt_tableview_resizecolumntocontents (Handle, column);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_resizecolumnstocontents (IntPtr raw);
		public void ResizeColumnsToContents ()
		{
			qt_tableview_resizecolumnstocontents (Handle);
		}

		public void SortByColumn (int column)
		{
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_grid_show (IntPtr raw, bool show);
		public void ShowGrid (bool show)
		{
			qt_tableview_grid_show (Handle, show);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_scrollto (IntPtr raw, int row, int col, ScrollHint hint);
		public void ScrollTo(int row, int col = 0, ScrollHint hint = ScrollHint.EnsureVisible)
		{
			qt_tableview_scrollto (Handle, row, col, hint);
		}
	}
}
