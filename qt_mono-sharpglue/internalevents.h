private:
	const char* _nameSpace;
protected:
	// Event handlers
	void mousePressEvent(QMouseEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doMousePressEvent(_thisObject, event);
		BaseClass::mousePressEvent(event);
	}
	void mouseReleaseEvent(QMouseEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doMouseReleaseEvent(_thisObject, event);
		BaseClass::mouseReleaseEvent(event);
	}
	void mouseDoubleClickEvent(QMouseEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doMouseDoubleClickEvent(_thisObject, event);
		BaseClass::mouseDoubleClickEvent(event);
	}
	void mouseMoveEvent(QMouseEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doMouseMoveEvent(_thisObject, event);
		BaseClass::mouseMoveEvent(event);
	}
#ifndef QT_NO_WHEELEVENT
	void wheelEvent(QWheelEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dowheelEvent(_thisObject, event);
		BaseClass::wheelEvent(event);
	}
#endif
	void keyPressEvent(QKeyEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dokeyPressEvent(_thisObject, event);
		BaseClass::keyPressEvent(event);
	}
	void keyReleaseEvent(QKeyEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dokeyReleaseEvent(_thisObject, event);
		BaseClass::keyReleaseEvent(event);
	}
	void focusInEvent(QFocusEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dofocusInEvent(_thisObject, event);
		BaseClass::focusInEvent(event);
	}
	void focusOutEvent(QFocusEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dofocusOutEvent(_thisObject, event);
		BaseClass::focusOutEvent(event);
	}
	void enterEvent(QEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doenterEvent(_thisObject, event);
		BaseClass::enterEvent(event);
	}
	void leaveEvent(QEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doleaveEvent(_thisObject, event);
		BaseClass::leaveEvent(event);
	}
	void paintEvent(QPaintEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dopaintEvent(_thisObject, event);
		BaseClass::paintEvent(event);
	}
	void moveEvent(QMoveEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			domoveEvent(_thisObject, event);
		BaseClass::moveEvent(event);
	}
	void resizeEvent(QResizeEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doresizeEvent(_thisObject, event);
		BaseClass::resizeEvent(event);
	}
	void closeEvent(QCloseEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			docloseEvent(_thisObject, event);
		BaseClass::closeEvent(event);
	}
#ifndef QT_NO_CONTEXTMENU
	void contextMenuEvent(QContextMenuEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			docontextMenuEvent(_thisObject, event);
		BaseClass::contextMenuEvent(event);
	}
#endif
#ifndef QT_NO_TABLETEVENT
	void tabletEvent(QTabletEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dotabletEvent(_thisObject, event);
		BaseClass::tabletEvent(event);
	}
#endif
#ifndef QT_NO_ACTION
	void actionEvent(QActionEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doactionEvent(_thisObject, event);
		BaseClass::actionEvent(event);
	}
#endif
#ifndef QT_NO_DRAGANDDROP
	void dragEnterEvent(QDragEnterEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dodragEnterEvent(_thisObject, event);
		BaseClass::dragEnterEvent(event);
	}
	void dragMoveEvent(QDragMoveEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dodragMoveEvent(_thisObject, event);
		BaseClass::dragMoveEvent(event);
	}
	void dragLeaveEvent(QDragLeaveEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dodragLeaveEvent(_thisObject, event);
		BaseClass::dragLeaveEvent(event);
	}
	void dropEvent(QDropEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dodropEvent(_thisObject, event);
		BaseClass::dropEvent(event);
	}
#endif
	void showEvent(QShowEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			doshowEvent(_thisObject, event);
		BaseClass::showEvent(event);
	}
	void hideEvent(QHideEvent *event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dohideEvent(_thisObject, event);
		BaseClass::hideEvent(event);
	}
	// Misc. protected functions
	void changeEvent(QEvent* event) override
	{
		//if (strcmp(_nameSpace, "Qt"))
			dochangeEvent(_thisObject, event);
		BaseClass::changeEvent(event);
	}
#undef BaseClass