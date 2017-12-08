GlueEvents::GlueEvents(MonoObject* thisObject)
{
}

void GlueEvents::keyPressEvent(QKeyEvent *keyEvent)
{
	dokeyPressEvent(_thisObject, keyEvent);
}

void GlueEvents::keyReleaseEvent(QKeyEvent *keyEvent)
{
	dokeyReleaseEvent(_thisObject, keyEvent);
}
//
//bool GlueEvents::event (QEvent* event)
//{
//	return doEvent(_thisObject, event);
//}

void GlueEvents::mousePressEvent (QMouseEvent *event)
{
	doMousePressEvent(_thisObject, event);
}

void GlueEvents::mouseReleaseEvent (QMouseEvent *event)
{
	doMouseReleaseEvent(_thisObject, event);
}

void GlueEvents::mouseDoubleClickEvent (QMouseEvent *event)
{
	doMouseDoubleClickEvent(_thisObject, event);
}

void GlueEvents::mouseMoveEvent (QMouseEvent *event)
{
	doMouseMoveEvent(_thisObject, event);
}
