using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class TableView : AbstractItemView
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tableview_new (TableView thisObject, IntPtr parent);

		protected TableView () : base(IntPtr.Zero) { }

		protected TableView (IntPtr raw) : base(raw) { }

		public TableView (Widget parent)  : base(IntPtr.Zero)
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
		protected static extern int qt_tableview_colwidth_get (IntPtr raw, int col);
		public int GetColumnWidth(int col)
		{
			return qt_tableview_colwidth_get (Handle, col);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_colwidth_set (IntPtr raw, int col, int width);
		public void SetColumnWidth(int col, int width)
		{
			qt_tableview_colwidth_set (Handle, col, width);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_selectcol (IntPtr raw, int col);
		public void SelectColumn (int col)
		{
			qt_tableview_selectcol (Handle, col);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_hiderow (IntPtr raw, int col);
		public void HideRow (int row)
		{
			qt_tableview_hiderow (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_showrow (IntPtr raw, int col);
		public void ShowRow (int row)
		{
			qt_tableview_showrow (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_hidecol (IntPtr raw, int col);
		public void HideColumn (int col)
		{
			qt_tableview_hidecol (Handle, col);
		}


		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_showcol (IntPtr raw, int col);
		public void ShowColumn (int col)
		{
			qt_tableview_showcol (Handle, col);
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
		protected static extern void qt_tableview_resizecoltocontents (IntPtr raw, int col);
		public void ResizeColumnToContents (int col)
		{
			qt_tableview_resizecoltocontents (Handle, col);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_resizecolstocontents (IntPtr raw);
		public void ResizeColumnsToContents ()
		{
			qt_tableview_resizecolstocontents (Handle);
		}

		public void SortByColumn (int col)
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
		public void ScrollTo(int row, int col, ScrollHint hint = ScrollHint.EnsureVisible)
		{
			qt_tableview_scrollto (Handle, row, col, hint);
		}


		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_tableview_rowheight_get (IntPtr raw, int row);
		public int GetRowHeight(int row)
		{
			return qt_tableview_rowheight_get (Handle, row);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_tableview_rowheight_set (IntPtr raw, int row, int height);
		public void SetRowHeight(int row, int height)
		{
			qt_tableview_rowheight_set (Handle, row, height);
		}
	}
}
