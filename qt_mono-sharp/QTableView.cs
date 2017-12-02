using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class TableView : ItemView
	{
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_tableview_new (TableView thisObject, IntPtr parent);

		protected TableView (IntPtr raw) : base (raw)
		{
		}

		public TableView () : this (null)
		{
		}

		public TableView (Widget parent) : base (IntPtr.Zero)
		{
			Raw = qt_tableview_new (this, parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_horizontalheader_get (IntPtr raw);

		public HeaderView HorizontalHeader {
			get {
				return new HeaderView (qt_widget_horizontalheader_get (Handle));
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_widget_verticalheader_get (IntPtr raw);

		public HeaderView VerticalHeader {
			get {
				return new HeaderView (qt_widget_verticalheader_get (Handle));
			}
		}

		public void SelectRow (object sender, int row)
		{
		}

		public void SelectColumn (object sender, int column)
		{
		}

		public void HideRow (object sender, int row)
		{
		}

		public void HideColumn (object sender, int column)
		{
		}

		public void ShowRow (object sender, int row)
		{
		}

		public void ShowColumn (object sender, int column)
		{
		}

		public void ResizeRowToContents (object sender, int row)
		{
		}

		public void ResizeRowsToContents (object sender)
		{
		}

		public void ResizeColumnToContents (object sender, int column)
		{
		}

		public void ResizeColumnsToContents (object sender)
		{
		}

		public void SortByColumn (object sender, int column)
		{
		}

		public void SetShowGrid (object sender, bool show)
		{
		}
	}
}
