/*
 * The Apache Software License, Version 1.1
 *
 *
 * Copyright (c) 1999-2002 The Apache Software Foundation.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *	  notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *	  notice, this list of conditions and the following disclaimer in
 *	  the documentation and/or other materials provided with the
 *	  distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *	  if any, must include the following acknowledgment:  
 *		 "This product includes software developed by the
 *		  Apache Software Foundation (http://www.apache.org/)."
 *	  Alternately, this acknowledgment may appear in the software itself,
 *	  if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Xalan" and "Apache Software Foundation" must
 *	  not be used to endorse or promote products derived from this
 *	  software without prior written permission. For written 
 *	  permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *	  nor may "Apache" appear in their name, without prior written
 *	  permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.	IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation and was
 * originally based on software copyright (c) 1999, International
 * Business Machines, Inc., http://www.ibm.com.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 */
#if !defined(XERCESDOCUMENTWRAPPER_HEADER_GUARD_1357924680)
#define XERCESDOCUMENTWRAPPER_HEADER_GUARD_1357924680



#include <XercesParserLiaison/XercesParserLiaisonDefinitions.hpp>



#include <deque>
#include <set>
#include <vector>



#include <XalanDOM/XalanDocument.hpp>



#if defined(XALAN_AUTO_PTR_REQUIRES_DEFINITION)
#include <XalanDOM/XalanDOMImplementation.hpp>
#include <PlatformSupport/XalanDOMStringPool.hpp>
#endif



#include <Include/XalanAutoPtr.hpp>



#include <XercesParserLiaison/XercesDOMWalker.hpp>
#include <XercesParserLiaison/XercesWrapperNavigator.hpp>


#include <XercesParserLiaison/XercesWrapperToXalanNodeMap.hpp>
#include <XercesParserLiaison/XercesNodeListWrapper.hpp>
#include <XercesParserLiaison/XercesAttrWrapperAllocator.hpp>
#include <XercesParserLiaison/XercesElementWrapperAllocator.hpp>
#include <XercesParserLiaison/XercesTextWrapperAllocator.hpp>



class DOMComment;
class DOMEntity;
class DOMEntityReference;
class DOMDocument;
class DOMDocumentType;
class DOMAttr;
class DOMElement;
class DOMCDATASection;
class DOMNotation;
class DOMText;
class DOMProcessingInstruction;

class XalanDOMStringPool;
class XercesCommentWrapper;
class XercesCDATASectionWrapper;
class XercesDocumentFragmentWrapper;
class XercesDocumentTypeWrapper;
class XercesEntityWrapper;
class XercesEntityReferenceWrapper;
class XercesProcessingInstructionWrapper;
class XercesNotationWrapper;



class XALAN_XERCESPARSERLIAISON_EXPORT XercesDocumentWrapper : public XalanDocument
{
public:

	friend class XercesWrapperNavigator;

	/**
	 *
	 * Constructor for XercesDocumentWrapper.
	 *
	 * If the document will be shared amongst multiple threads of execution,
	 * the parameter buildWrapper must be true.  Otherwise, the bridge
	 * nodes will be built on demand, a process which is not synchronized.
	 * This could cause serious problems if multiple threads tried to visit
	 * an unbuilt node at the same time.
	 *
	 * @param theXercesDocument The Xerces document to bridge
	 * @param threadSafe If true, the tree can safely be shared amongst multiple threads.  (Also implies buildWrapper == true)
	 * @param buildWrapper If true, all of the bridge nodes will be built during construction.
	 *
	 */
	XercesDocumentWrapper(
			const DOMDocument*	theXercesDocument,
			bool				threadSafe = true,
			bool				buildWrapper = true);

	virtual
	~XercesDocumentWrapper();

	// These interfaces are inherited from XalanNode...

	virtual const XalanDOMString&
	getNodeName() const;

	virtual const XalanDOMString&
	getNodeValue() const;

	virtual NodeType
	getNodeType() const;

	virtual XalanNode*
	getParentNode() const;

	virtual const XalanNodeList*
	getChildNodes() const;

	virtual XalanNode*
	getFirstChild() const;

	virtual XalanNode*
	getLastChild() const;

	virtual XalanNode*
	getPreviousSibling() const;

	virtual XalanNode*
	getNextSibling() const;

	virtual const XalanNamedNodeMap*
	getAttributes() const;

	virtual XalanDocument*
	getOwnerDocument() const;

#if defined(XALAN_NO_COVARIANT_RETURN_TYPE)
	virtual XalanNode*
#else
	virtual XercesDocumentWrapper*
#endif
	cloneNode(bool deep) const;

	virtual XalanNode*
	insertBefore(
			XalanNode*	newChild,
			XalanNode*	refChild);

	virtual XalanNode*
	replaceChild(
			XalanNode*	newChild,
			XalanNode*	oldChild);

	virtual XalanNode*
	removeChild(XalanNode*	oldChild);

	virtual XalanNode*
	appendChild(XalanNode*	newChild);

	virtual bool
	hasChildNodes() const;

	virtual void
	setNodeValue(const XalanDOMString&		nodeValue);

	virtual void
	normalize();

	virtual bool
	isSupported(
			const XalanDOMString&	feature,
			const XalanDOMString&	version) const;

	virtual const XalanDOMString&
	getNamespaceURI() const;

	virtual const XalanDOMString&
	getPrefix() const;

	virtual const XalanDOMString&
	getLocalName() const;

	virtual void
	setPrefix(const XalanDOMString& prefix);

	virtual bool
	isIndexed() const;

	virtual unsigned long
	getIndex() const;

	virtual XalanElement*
	createElement(const XalanDOMString& tagName);

	virtual XalanDocumentFragment*
	createDocumentFragment();

	virtual XalanText*
	createTextNode(const XalanDOMString&	data);

	virtual XalanComment*
	createComment(const XalanDOMString& data);

	virtual XalanCDATASection*
	createCDATASection(const XalanDOMString&	data);

	virtual XalanProcessingInstruction*
	createProcessingInstruction(
			const XalanDOMString&	target,
			const XalanDOMString&	data);

	virtual XalanAttr*
	createAttribute(const XalanDOMString&	name);

	virtual XalanEntityReference*
	createEntityReference(const XalanDOMString& name);

	virtual XalanDocumentType*
	getDoctype() const;

	virtual XalanDOMImplementation*
	getImplementation() const;

	virtual XalanElement*
	getDocumentElement() const;

	virtual XalanNodeList*
	getElementsByTagName(const XalanDOMString&		tagname) const;

	virtual XalanNode*
	importNode(
			XalanNode*	importedNode,
			bool		deep);

	virtual XalanElement*
	createElementNS(
			const XalanDOMString&	namespaceURI,
			const XalanDOMString&	qualifiedName);

	virtual XalanAttr*
	createAttributeNS(
			const XalanDOMString& namespaceURI,
			const XalanDOMString& qualifiedName);

	virtual XalanNodeList*
	getElementsByTagNameNS(
			const XalanDOMString&	namespaceURI,
			const XalanDOMString&	localName) const;

	virtual XalanElement*
	getElementById(const XalanDOMString&	elementId) const;

	// These are some special interfaces to manage relationships between
	// our nodes and Xerces nodes.

	/**
	 * Destroy the entire bridge structure that connects
	 * the Xerces document to this XercesDocumentWrapper
	 * instance.  This will invalidate any pointers to
	 * any nodes in the document (except, of course, the
	 * document itself).
	 */
	void
	destroyWrapper();

	/**
	 * Rebuild the entire bridge structure that connects
	 * the Xerces document to this XercesDocumentWrapper
	 * instance.  This destroys the bridge before
	 * rebuilding.
	 */
	void
	rebuildWrapper();

	XalanNode*
	mapNode(const DOMNode* 	theXercesNode) const;

	XalanAttr*
	mapNode(const DOMAttr* 		theXercesNode) const;

	XalanElement*
	mapNode(const DOMElement* 	theXercesNode) const;

	const DOMNode*
	mapNode(XalanNode* 	theXalanNode) const;

	const DOMAttr*
	mapNode(XalanAttr* 	theXalanNode) const;

	/**
	 *
	 * Get the Xerces DOMDocument that this XercesDocument represents.
	 *
	 * @return the Xerces DOMDocument instance.
	 *
	 */
	const DOMDocument*
	getXercesDocument() const
	{
		return m_xercesDocument;
	}

	/**
	 * Build the entire bridge structure.  This should be done before any
	 * processing begins, if the tree will be shared amongst multiple
	 * threads.
	 */
	void
	buildWrapperNodes();

#if defined(XALAN_NO_NAMESPACES)
	typedef deque<XercesWrapperNavigator>	WrapperNavigatorVectorType;

	typedef deque<XalanNode*>				NodeVectorType;
#else
	typedef std::deque<XercesWrapperNavigator>	WrapperNavigatorVectorType;

	typedef std::deque<XalanNode*>				NodeVectorType;
#endif

	// Helper class to walk the tree and build everything...
	class BuildWrapperTreeWalker : public XercesDOMWalker
	{
	public:

		typedef WrapperNavigatorVectorType	WrapperNavigatorVectorInnerType;

		BuildWrapperTreeWalker(
				XercesDocumentWrapper*				theDocument,
				XercesWrapperNavigator*				theDocumentNavigator,
				WrapperNavigatorVectorInnerType&	theNavigators,
				unsigned long						theStartIndex);

		virtual
		~BuildWrapperTreeWalker();

		struct NavigatorStackEntryType
		{
			NavigatorStackEntryType(
						XercesWrapperNavigator*	theNavigator = 0,
						XalanNode*				theNode = 0) :
				m_navigator(theNavigator),
				m_node(theNode)
			{
			}

			XercesWrapperNavigator*	m_navigator;

			XalanNode*				m_node;
		};

	#if defined(XALAN_NO_NAMESPACES)
		typedef vector<NavigatorStackEntryType>			NavigatorStackType;
	#else
		typedef std::vector<NavigatorStackEntryType>	NavigatorStackType;
	#endif

	protected:

		virtual void
		startNode(const DOMNode*	node);

		virtual void
		endNode(const DOMNode*		node);

	private:

		XercesDocumentWrapper*				m_document;

		WrapperNavigatorVectorInnerType&	m_navigators;

		unsigned long						m_currentIndex;

		NavigatorStackType					m_parentNavigatorStack;

		NavigatorStackType					m_siblingNavigatorStack;
	};


	/**
	 * Get a pooled string.  If the string is not in the pool,
	 * add it.
	 *
	 * @param theString The string to pool.
	 * @return A const reference to the pooled string.
	 */
	const XalanDOMString&
	getPooledString(const XalanDOMString&	theString) const;

	/**
	 * Get a pooled string.  If the string is not in the pool,
	 * add it.
	 *
	 * @param theString The string to pool.
	 * @param theLength The length of the string.  If XalanDOMString::npos, the string is assumed to be null-terminated.
	 * @return A const reference to the pooled string.
	 */
	const XalanDOMString&
	getPooledString(
			const XalanDOMChar*			theString,
			XalanDOMString::size_type	theLength /* = XalanDOMString::npos */) const;

private:

	// Destruction API...
	void
	destroyWrapperNode(XalanNode*	theNode);

	// Not implemented...
	XercesDocumentWrapper(const XercesDocumentWrapper&	theSource);

	XercesDocumentWrapper&
	operator=(const XercesDocumentWrapper&	theRHS);

	bool
	operator==(const XercesDocumentWrapper&	theRHS) const;

	// Private delete function...
	void
	destroyNode(XalanNode*	theNode);

	// More internal implementation stuff...

	// Factory methods for our implementation nodes...
	XalanNode*
	createWrapperNode(
			const DOMNode*	theXercesNode,
			unsigned long	theIndex,
			bool			mapNode) const;

	XercesDocumentTypeWrapper*
	createWrapperNode(
			const DOMDocumentType*	theDoctype,
			unsigned long			theIndex,
			bool					mapNode) const;

	XercesElementWrapper*
	createWrapperNode(
			const DOMElement* 	theXercesNode,
			unsigned long		theIndex,
			bool				mapNode) const;

	XercesTextWrapper*
	createWrapperNode(
			const DOMText*		theXercesNode,
			unsigned long		theIndex,
			bool				mapNode) const;

	XercesCommentWrapper*
	createWrapperNode(
			const DOMComment*	theXercesNode,
			unsigned long		theIndex,
			bool				mapNode) const;

	XercesCDATASectionWrapper*
	createWrapperNode(
			const DOMCDATASection*		theXercesNode,
			unsigned long				theIndex,
			bool						mapNode) const;

	XercesProcessingInstructionWrapper*
	createWrapperNode(
			const DOMProcessingInstruction*		theXercesNode,
			unsigned long						theIndex,
			bool								mapNode) const;

	XercesAttrWrapper*
	createWrapperNode(
			const DOMAttr*		theXercesNode,
			unsigned long		theIndex,
			bool				mapNode) const;

	XercesEntityWrapper*
	createWrapperNode(
			const DOMEntity*	theXercesNode,
			unsigned long		theIndex,
			bool				mapNode) const;

	XercesEntityReferenceWrapper*
	createWrapperNode(
			const DOMEntityReference*	theXercesNode,
			unsigned long				theIndex,
			bool						mapNode) const;

	XercesNotationWrapper*
	createWrapperNode(
			const DOMNotation*		theXercesNode,
			unsigned long			theIndex,
			bool					mapNode) const;

	XercesWrapperNavigator&
	pushNavigator(bool	mappingMode) const;

	// This is a private helper class for building the tree...
	friend class BuildWrapperTreeWalker;

	const DOMDocument* const				m_xercesDocument;

	XalanElement*							m_documentElement;

	mutable XercesWrapperToXalanNodeMap		m_nodeMap;

	XalanAutoPtr<XalanDOMImplementation>	m_domImplementation;

	mutable WrapperNavigatorVectorType		m_navigators;

	// Our navigator will be the first entry in m_navigators,
	// but we'll cache this so access is faster...
	XercesWrapperNavigator*					m_navigator;

	XercesNodeListWrapper					m_children;

	mutable NodeVectorType					m_nodes;

	mutable XercesDocumentTypeWrapper* 		m_doctype;

	bool									m_mappingMode;

	bool									m_indexValid;

	mutable XercesElementWrapperAllocator	m_elementAllocator;

	mutable XercesTextWrapperAllocator		m_textAllocator;

	mutable XercesAttrWrapperAllocator		m_attributeAllocator;

	const XalanAutoPtr<XalanDOMStringPool>	m_stringPool;
};



#endif	// !defined(XERCESDOCUMENTWRAPPER_HEADER_GUARD_1357924680)
