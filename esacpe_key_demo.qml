function handleKey(key)
    {
        if (!imageRect.visible)
            return false;
        switch (key) {
        case Qt.Key_Left:
            previousImage();
            return true;
        case Qt.Key_Right:
            nextImage();
            return true;
	case Qt.Key_Escape:    /* A short approach for implementation */ 
	    homeMenu();		/* A user defined function as nextImage() and previousImage();			
        }