
// TestMFCView.cpp : implementation of the CTestMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestMFC.h"
#endif

#include "TestMFCDoc.h"
#include "TestMFCView.h"
#include "Renderer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMFCView

IMPLEMENT_DYNCREATE(CTestMFCView, CView)

BEGIN_MESSAGE_MAP(CTestMFCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTestMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTestMFCView construction/destruction

CTestMFCView::CTestMFCView()
{
	// TODO: add construction code here

}

CTestMFCView::~CTestMFCView()
{
}

BOOL CTestMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTestMFCView drawing

void CTestMFCView::OnDraw(CDC* /*pDC*/)
{
	CTestMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	Renderer::Update(GetSafeHwnd());
	Invalidate(FALSE);
}


// CTestMFCView printing


void CTestMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTestMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTestMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTestMFCView diagnostics

#ifdef _DEBUG
void CTestMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CTestMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestMFCDoc* CTestMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestMFCDoc)));
	return (CTestMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestMFCView message handlers


void CTestMFCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();


}


void CTestMFCView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	Renderer::OnSize(GetSafeHwnd());
}


BOOL CTestMFCView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	return CView::OnEraseBkgnd(pDC);
}


BOOL CTestMFCView::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	Renderer::Destroy(GetSafeHwnd());
	return CView::DestroyWindow();
}


void CTestMFCView::OnDestroy()
{
	Renderer::Destroy(GetSafeHwnd());
	CView::OnDestroy();

	// TODO: Add your message handler code here
}


int CTestMFCView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	// TODO: Add your specialized code here and/or call the base class
	Renderer::Init(GetSafeHwnd());
	return 0;
}
