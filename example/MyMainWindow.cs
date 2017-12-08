using System;
using Qt;
using System.Diagnostics;

namespace TestQtMonoSharp
{
	public class MyMainWindow : MainWindow
	{
		[UiLoader ()]
		TableWidget tableView;

		public MyMainWindow (Qt.Widget parent = null)
			: base (parent, "./mainwindow.ui")
		{
			//tableView = new TableView (this);

//			var model = new ItemModel (this);
//			model.ColumnCount = 5;
//			model.RowCount = 10;
//			model.SetItem (1, new StandardItem ("LINE1"));
//			model.SetItem (2, new StandardItem ("LINE2"));
//			tableView.Model = model;

			tableView.ColumnCount = 5;
			tableView.RowCount = 5;
			tableView.SetItem (0, 1, new TableWidgetItem ("LINE1"));
			tableView.SetItem (1, 1, new TableWidgetItem ("LINE2"));

			tableView.ResizeRowsToContents ();
			tableView.SetColumnWidth (0, 350);
			tableView.SelectColumn (1);
			tableView.SelectRow (1);

			//tableView.ShowGrid (false);

			//tableView.VerticalHeader.Visible = false;
		}

		void MyMainWindow_CloseEvent (object sender, Qt.CloseEvent e)
		{
			//e.Ignore ();
		}
	}
}

