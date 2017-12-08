using System;
using System.Runtime.InteropServices;
using System.Runtime.CompilerServices;

namespace Qt
{
	public class ItemView : ScrollArea
	{
		public enum SelectionMode
		{
			NoSelection,
			SingleSelection,
			MultiSelection,
			ExtendedSelection,
			ContiguousSelection
		}

		public enum SelectionBehavior
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

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_abstractitemview_new (IntPtr parent);

		protected ItemView (IntPtr raw) : base (raw)
		{
			if (GetType () != typeof(ItemView))
				return;
			Raw = qt_abstractitemview_new (raw);
		}

		protected ItemView (Widget parent) : base (IntPtr.Zero)
		{
			if (GetType () != typeof(ItemView))
				return;
			Raw = qt_abstractitemview_new (parent != null ? parent.Handle : IntPtr.Zero);
		}

		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern IntPtr qt_itemview_model_get (IntPtr parent);
		[MethodImpl (MethodImplOptions.InternalCall)]
		protected static extern void qt_itemview_model_set (IntPtr parent, IntPtr item);
		public ItemModel Model
		{
			get
			{
				var model = qt_itemview_model_get (Handle);
				return GetObjectFromRaw (model) as ItemModel;
			}
			set
			{
				qt_itemview_model_set (Handle, value.Handle);
			}
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
