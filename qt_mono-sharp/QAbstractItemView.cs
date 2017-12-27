using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public abstract class AbstractItemView : AbstractScrollArea
	{
		public enum SelectionModeEnum
		{
			NoSelection,
			SingleSelection,
			MultiSelection,
			ExtendedSelection,
			ContiguousSelection
		}

		public enum SelectionBehaviorEnum
		{
			SelectItems,
			SelectRows,
			SelectColumns
		}

		public enum ScrollHint
		{
			EnsureVisible,
			PositionAtTop,
			PositionAtBottom,
			PositionAtCenter
		}

		[Flags]
		public enum EditTriggers
		{
			NoEditTriggers = 0,
			CurrentChanged = 1,
			DoubleClicked = 2,
			SelectedClicked = 4,
			EditKeyPressed = 8,
			AnyKeyPressed = 16,
			AllEditTriggers = 31
		}

		public enum ScrollMode
		{
			ScrollPerItem,
			ScrollPerPixel
		}

		public enum DragDropMode
		{
			NoDragDrop,
			DragOnly,
			DropOnly,
			DragDrop,
			InternalMove
		}

		public event EventHandler<ModelIndex> Pressed;
		public event EventHandler<ModelIndex> Clicked;
		public event EventHandler<ModelIndex> DoubleClicked;
		public event EventHandler<ModelIndex> Activated;
		public event EventHandler<ModelIndex> Entered;
		public event EventHandler ViewportEntered;
		public event EventHandler<Size> IconSizeChanged;

//		[MethodImpl (MethodImplOptions.InternalCall)]
//		protected static extern IntPtr qt_abstractitemview_new (IntPtr parent);
//
//		protected ItemView () {	}
//
		protected AbstractItemView (IntPtr raw) : base (raw) { }
//
//		public ItemView (Widget parent)
//		{
//			if (Raw != IntPtr.Zero)
//				throw new ArgumentException ("Raw not null!");
//			Raw = qt_abstractitemview_new (parent != null ? parent.Handle : IntPtr.Zero);
//		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_itemview_model_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemview_model_set (IntPtr parent, IntPtr item);
		public StandardItemModel Model
		{
			get
			{
				var model = qt_itemview_model_get (Handle);
				return GetObjectFromRaw (model) as StandardItemModel;
			}
			set
			{
				qt_itemview_model_set (Handle, value.Handle);
			}
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern SelectionBehaviorEnum qt_itemview_selectctionbehavior_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemview_selectctionbehavior_set (IntPtr parent, SelectionBehaviorEnum selectionBehavior);
		public SelectionBehaviorEnum SelectionBehavior
		{
			get{ return qt_itemview_selectctionbehavior_get (Handle); }
			set{ qt_itemview_selectctionbehavior_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern SelectionModeEnum qt_itemview_selectctionmode_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemview_selectctionmode_set (IntPtr parent, SelectionModeEnum selectionBehavior);
		public SelectionModeEnum SelectionMode
		{
			get{ return qt_itemview_selectctionmode_get (Handle); }
			set{ qt_itemview_selectctionmode_set (Handle, value); }
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern int qt_itemview_autoscrollmargin_get (IntPtr raw);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemview_autoscrollmargin_set (IntPtr raw, int autoscrollmargin);
		public int AutoScrollMargin
		{
			get{ return qt_itemview_autoscrollmargin_get (Handle); }
			set{ qt_itemview_autoscrollmargin_set (Handle, value); }
		}

		void OnPressed (ModelIndex index)
		{
			var tmp = Pressed;
			tmp?.Invoke (this, index);
		}

		void OnClicked (ModelIndex index)
		{
			var tmp = Clicked;
			tmp?.Invoke (this, index);
		}

		void OnDoubleClicked (ModelIndex index)
		{
			var tmp = DoubleClicked;
			tmp?.Invoke (this, index);
		}

		void OnActivated (ModelIndex index)
		{
			var tmp = Activated;
			tmp?.Invoke (this, index);
		}

		void OnEntered (ModelIndex index)
		{
			var tmp = Entered;
			tmp?.Invoke (this, index);
		}

		void OnViewportEntered (ModelIndex index)
		{
			var tmp = ViewportEntered;
			tmp?.Invoke (this, new EventArgs ());
		}

		void OnIconSizeChanged (Size size)
		{
			var tmp = IconSizeChanged;
			tmp?.Invoke (this, size);
		}
	}
}
