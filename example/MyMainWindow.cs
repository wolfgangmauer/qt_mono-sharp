using System;
using Qt;
using System.Diagnostics;

namespace TestQtMonoSharp
{
	public class MyMainWindow : MainWindow
	{
		[UiLoader ()]
		TableView tableView;

		public MyMainWindow (Qt.Widget parent=null)
			: base (parent, "./mainwindow.ui")
		{
			//tableView = new TableView (this);

			var model = new StandardItemModel (this);
			model.ColumnCount = 5;
			model.RowCount = 10;
			model.SetItem (0, 0, new StandardItem ("LINE:0_0"));
			model.SetItem (0, 1, new StandardItem ("LINE_0_1"));
			model.SetItem (1, 0, new StandardItem ("LINE_1_0"));
			model.SetItem (1, 1, new StandardItem ("LINE_1_1"));

			model.SetItem (3, 0, new StandardItem ("LINE_3_0"));
			model.SetItem (3, 1, new StandardItem ("LINE_3_1"));

			tableView.Model = model;

			tableView.Font = new Font ("Ubuntu Condensed Regular", 30);
//			tableView.ColumnCount = 5;
//			tableView.RowCount = 5;
//			tableView.SetItem (0, 0, new TableWidgetItem ("LINE:0_0"));
//			tableView.SetItem (0, 1, new TableWidgetItem ("LINE_0_1"));
//			tableView.SetItem (1, 0, new TableWidgetItem ("LINE_1_0"));
//			tableView.SetItem (1, 1, new TableWidgetItem ("LINE_1_1"));

			tableView.ResizeRowsToContents ();
			tableView.SetColumnWidth (0, 350);

			tableView.ShowGrid (false);

			tableView.VerticalHeader.Visible = false;
			tableView.HorizontalHeader.Visible = false;

			tableView.SelectionBehavior = ItemView.SelectionBehaviorEnum.SelectRows;
			tableView.SelectionMode = ItemView.SelectionModeEnum.SingleSelection;

			tableView.SelectRow (1);

//			HeaderView verticalHeader = tableView.VerticalHeader;
//			verticalHeader.SetSectionResizeMode(HeaderView.ResizeMode.Fixed);
//			verticalHeader.DefaultSectionSize = 50;

			tableView.ResizeRowsToContents ();

			tableView.ScrollTo (1, 0);
		}

		void MyMainWindow_CloseEvent (object sender, Qt.CloseEvent e)
		{
			//e.Ignore ();
		}
	}
}

